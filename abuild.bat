@SETLOCAL ENABLEEXTENSIONS
@ECHO OFF

SET SCONS_PATH="%~dp0\tools\scons\scons.py"
SET SCONS_TOOLS="%~dp0\tools\scons-custom"
SET SCONS=python -B %SCONS_PATH%

SET PYTHONPATH=%SCONS_TOOLS%
%SCONS% --site-dir=%SCONS_TOOLS% %*
