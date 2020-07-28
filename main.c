#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"

static void * tick_thread(void * arg)
{
    const struct timespec period = {
        .tv_sec = 0,
        .tv_nsec = 5000000UL,
    };

    struct timespec remaining;

    while(1) {
        nanosleep(&period, &remaining);
        lv_tick_inc(5);
    }

    return arg;
}

void dev_init(void)
{
    static lv_disp_buf_t disp_buf;
    static lv_color_t buffer[480 * 64];
    lv_disp_buf_init(&disp_buf, buffer, NULL, 480 * 64);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.buffer = &disp_buf;

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);

    monitor_init();
    mouse_init();

    disp_drv.flush_cb = monitor_flush;

    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read;

    lv_disp_drv_register(&disp_drv);
    lv_indev_drv_register(&indev_drv);
}

int main(int argc, char *argv[])
{
    lv_init();
    dev_init();

    pthread_t pid;
    pthread_create(&pid, NULL, tick_thread, NULL);

    const struct timespec period = {
        .tv_sec = 0,
        .tv_nsec = 5000000UL,
    };

    struct timespec remaining;

    while(1) {
        lv_task_handler();
        nanosleep(&period, &remaining);   // trigger every 5ms.
    }

    return 0;
}
