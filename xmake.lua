set_project("trng2")
set_allowedarchs("x86")
add_rules("mode.debug","mode.release","mode.releasedbg","mode.minsizerel","mode.check","mode.ubsan","mode.tsan","mode.lsan","mode.asan","mode.valgrind","mode.profile","plugin.compile_commands.autoupdate", {outputdir = "$(buildir)"})
if is_plat("windows") then
    add_defines("WIN32_LEAN_AND_MEAN","NOMINMAX","VC_EXTRALEAN","_CRT_SECURE_NO_WARNINGS")
end
includes("*/xmake.lua")