project('miadev', [ 'c', 'cpp' ],
    version: '0.0.1',
    meson_version: '>= 0.63',
    license: 'GPL2+'
    )

sdcc = find_program('sdcc', required : true)
sdcc_args = [ '--Werror', '--std-c99']

if false
libcos51 = c.find_library('cos51')
libcos51_m = c.find_library('cos51medium', 
    dirs: join_paths(meson.current_source_dir(), '/lib')
    )

sdk_dep = declare_dependency(
    include_directories: [
        # include_directories('arch/cos51')
    ],
    dependencies: libcos51
)
endif

subdir('arch')
subdir('test')
