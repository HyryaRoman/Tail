IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Tail/vendor/glfw"
IncludeDir["GLAD"] = "%{wks.location}/Tail/vendor/glad"
IncludeDir["ImGui"] = "%{wks.location}/Tail/vendor/ImGui"

workspace "Tail"
    startproject "Tail"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

group "Dependencies"
    include "Tail/vendor/glfw"
    include "Tail/vendor/glad"
    include "Tail/vendor/imgui"
group ""

include "Tail"