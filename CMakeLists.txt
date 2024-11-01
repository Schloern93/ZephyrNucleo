cmake_minimum_required(VERSION 3.20.0)

# Setze das Zielboard
set(BOARD nucleo_g491re)  # Ersetze dies durch den Namen deines Nucleo-Boards

# Setze ZEPHYR_BASE
set(ZEPHYR_BASE "${CMAKE_CURRENT_SOURCE_DIR}/libs/zephyr")

# Include Zephyr
find_package(Zephyr REQUIRED HINTS ${ZEPHYR_BASE})

# Projektdefinition
project(my_project)

# Hier kommen deine Quell- und Header-Dateien
target_sources(app PRIVATE source/main.c)