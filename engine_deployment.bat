@echo off
echo -Running Engine DLL configuration-

set src_path=%~1
set out_dir=%~2

echo using source: %src_path%
echo and destination: %out_dir%

cd "%src_path%"

echo step 1: Check destination folder

if not exist "%out_dir%\" (
	echo Creating bin directory at: %out_dir%
	mkdir "%out_dir%"
)

echo step 2: Copying library dependencies

echo copying Engine files to %out_dir%
copy "%src_path%Engine.dll" "%out_dir%" /y
copy "%src_path%glew32.dll" "%out_dir%" /y

echo -Configuration done-