#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define ANALOG_PIN "/sys/devices/12d10000.adc/iio:device0/in_voltage0_raw"
#define PWM_PIN "/sys/class/pwm/pwmchip0/pwm0/duty_cycle"

void write_pwm(int value) {
    int pwm_fd = open(PWM_PIN, O_WRONLY);
    if (pwm_fd == -1) {
        perror("Failed to open PWM pin");
        exit(1);
    }
    char buf[10];
    snprintf(buf, sizeof(buf), "%d", value);
    write(pwm_fd, buf, strlen(buf));
    close(pwm_fd);
}

int read_analog() {
    int analog_fd = open(ANALOG_PIN, O_RDONLY);
    if (analog_fd == -1) {
        perror("Failed to open analog pin");
        exit(1);
    }
    char buf[10];
    read(analog_fd, buf, sizeof(buf));
    close(analog_fd);
    return atoi(buf);
}

int main() {
    int led = 9; // Assuming pin 9 for PWM
    int flexposition;

    while (1) {
        flexposition = read_analog();

        printf("sensor: %d\n", flexposition);

        // Map flexposition value from 0-1023 to 0-255 for PWM
        int pwm_value = (int)((float)flexposition / 1023.0 * 255.0);

        write_pwm(pwm_value);

        usleep(20000); // 20ms delay
    }

    return 0;
}