@echo off
for /R %%f in (shader.*) do (
pushd %%~pf
C:\VulkanSDK\1.1.73.0\Bin32\glslangValidator -V %%f 
popd
)
