import os
import sys

path = os.getcwd() + "\\shaders\\"
if len(sys.argv) > 1:
    path = sys.argv[1]
inputs = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f)) and f.endswith(".glsl")]
glsl_compiler = "C:\\VulkanSDK\\1.2.176.0\\Bin\\glslc.exe"

for input in inputs:

    input_file = open("shaders\\"+input, 'r')
    lines = input_file.readlines()
    current_type = ''
    sources = {
        "vertex": "",
        "fragment": "",
    }

    for line in lines:
        if line.startswith("#type "):
            current_type = line.replace("#type ", "")[:-1]
        else:
            sources[current_type] += line
    input_file.close()

    output_root = input[:-5]
    batch = open("compile.bat", "w")
    batch.write("@echo off\n")
    for source in sources:
        output = output_root + "." + source
        output_file = open(output, "w")
        output_file.write(sources[source])
        command = glsl_compiler + " -O -fshader-stage=" + source + " " + output + " -o bin/" + output + ".spv"
        batch.write(command+"\n")
    batch.write("del shader.vertex\ndel shader.fragment\ndel compile.bat\n")
    os.system("compile.bat")
