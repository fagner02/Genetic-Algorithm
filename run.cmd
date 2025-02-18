del main.exe
g++ -std=c++17 -static -static-libgcc -static-libstdc++ -pthread -Wl,-Bstatic -DSFML_STATIC -LC:\msys64\mingw32\lib -I.\include -IC:\msys64\mingw32\include ^
src\main.cpp ^
src\structures.cpp ^
src\print.cpp ^
src\genetic_algo.cpp ^
src\experiments.cpp ^
src\point.cpp ^
src\ui\RoundRectangle.cpp ^
src\ui\hsl.cpp ^
src\ui\Input.cpp ^
src\ui\TextBox.cpp ^
src\ui\Row.cpp ^
src\ui\CenterBox.cpp ^
src\ui\InstructionText.cpp ^
src\ui\Column.cpp ^
src\ui\Clickable.cpp ^
src\ui\ClickableLabel.cpp ^
-lsfml-graphics-s ^
-lsfml-window-s ^
-lsfml-system-s ^
-lwinmm ^
-lopengl32 ^
-lgdi32 ^
-lfreetype ^
-lpng16 ^
-lz ^
-ljpeg ^
-lbz2 ^
-lpthread ^
-lharfbuzz ^
-lgraphite2 ^
-lstdc++fs ^
-lbrotlidec ^
-lbrotlienc ^
-lbrotlicommon ^
-lusp10 ^
-lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32 ^
-lrpcdce4 -lrpcrt4 ^
-o main.exe
@REM g++ -std=c++17 -Wall -Wextra -LC:\msys64\mingw32\lib -I.\include -IC:\msys64\mingw32\include -o main.exe ^
@REM src\structures.cpp ^
@REM src\print.cpp ^
@REM src\costs.cpp ^
@REM src\main.cpp ^
@REM src\path_finding.cpp ^
@REM src\heuristics.cpp
.\main.exe