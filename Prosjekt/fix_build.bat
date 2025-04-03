@echo off
echo Fixing Meson Build Issues...

:: Step 1: Delete the existing build directory
echo Removing old build directory...
rmdir /s /q builddir

:: Step 2: Recreate the build directory
echo Recreating build directory...
meson setup builddir

:: Step 3: Ensure json.hpp exists in the correct path
echo Checking for nlohmann/json.hpp...
if not exist subprojects\nlohmann_json-3.11.3\single_include\nlohmann\json.hpp (
    echo ERROR: json.hpp not found! Attempting to download...
    meson wrap install nlohmann_json
) else (
    echo json.hpp found!
)

:: Step 4: Reconfigure Meson to include nlohmann_json
echo Configuring Meson to include nlohmann_json...
meson setup --reconfigure builddir

:: Step 5: Compile the project
echo Compiling the project...
meson compile -C builddir

echo Build process complete!
pause
