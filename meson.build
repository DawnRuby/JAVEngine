project(
    'JAVEngine',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++23'],
)

add_project_arguments(
    ['-fvisibility=hidden', '-fvisibility-inlines-hidden'],
    language: 'cpp',
)

glfw3_dep = dependency('glfw3')
vulkan_dep = dependency('vulkan')

incdir = include_directories('JAVEngine')
sources = ['JAVEngine/main.cpp', 'JAVEngine/engine.cpp']

executable(
    'JAVEngine',
    sources,
    include_directories: incdir,
    dependencies: [glfw3_dep, vulkan_dep],
    install: true,
)
