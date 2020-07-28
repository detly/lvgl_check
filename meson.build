project('lvgl_check', 'c')

lvgl_sources = [
    'lvgl/lvgl/src/lv_core/lv_disp.c',
    'lvgl/lvgl/src/lv_core/lv_group.c',
    'lvgl/lvgl/src/lv_core/lv_indev.c',
    'lvgl/lvgl/src/lv_core/lv_obj.c',
    'lvgl/lvgl/src/lv_core/lv_refr.c',
    'lvgl/lvgl/src/lv_core/lv_style.c',

    'lvgl/lvgl/src/lv_draw/lv_draw_blend.c',
    'lvgl/lvgl/src/lv_draw/lv_draw_label.c',
    'lvgl/lvgl/src/lv_draw/lv_draw_line.c',
    'lvgl/lvgl/src/lv_draw/lv_draw_mask.c',
    'lvgl/lvgl/src/lv_draw/lv_draw_rect.c',
    'lvgl/lvgl/src/lv_draw/lv_draw_img.c',
    'lvgl/lvgl/src/lv_draw/lv_img_buf.c',
    'lvgl/lvgl/src/lv_draw/lv_img_cache.c',
    'lvgl/lvgl/src/lv_draw/lv_img_decoder.c',

    'lvgl/lvgl/src/lv_font/lv_font.c',
    'lvgl/lvgl/src/lv_font/lv_font_fmt_txt.c',
    'lvgl/lvgl/src/lv_font/lv_font_montserrat_16.c',

    'lvgl/lvgl/src/lv_hal/lv_hal_disp.c',
    'lvgl/lvgl/src/lv_hal/lv_hal_indev.c',
    'lvgl/lvgl/src/lv_hal/lv_hal_tick.c',

    'lvgl/lvgl/src/lv_misc/lv_anim.c',
    'lvgl/lvgl/src/lv_misc/lv_area.c',
    'lvgl/lvgl/src/lv_misc/lv_async.c',
    'lvgl/lvgl/src/lv_misc/lv_color.c',
    'lvgl/lvgl/src/lv_misc/lv_debug.c',
    'lvgl/lvgl/src/lv_misc/lv_fs.c',
    'lvgl/lvgl/src/lv_misc/lv_gc.c',
    'lvgl/lvgl/src/lv_misc/lv_ll.c',
    'lvgl/lvgl/src/lv_misc/lv_math.c',
    'lvgl/lvgl/src/lv_misc/lv_mem.c',
    'lvgl/lvgl/src/lv_misc/lv_task.c',
    'lvgl/lvgl/src/lv_misc/lv_txt.c',
    'lvgl/lvgl/src/lv_misc/lv_utils.c',

    'lvgl/lvgl/src/lv_themes/lv_theme.c',
    'lvgl/lvgl/src/lv_themes/lv_theme_empty.c',

    'lvgl/lv_drivers/display/monitor.c',
    'lvgl/lv_drivers/indev/mouse.c',
]

c_args = [
    '-Wall',
    '-Werror-implicit-function-declaration',
    '-DUSE_MONITOR',
    '-DUSE_MOUSE',
 ]

dep_threads = dependency('threads')

cc = meson.get_compiler('c')

dep_math = cc.find_library('m', required : false)

dep_sdl = cc.find_library('SDL2')

executable(
    'lvgl_check',
    sources : ['main.c'] + lvgl_sources,
    include_directories : ['lvgl'],
    dependencies : [dep_math, dep_threads, dep_sdl],
    c_args : c_args
)
