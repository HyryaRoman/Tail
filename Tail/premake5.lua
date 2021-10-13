project "Tail"
    kind "WindowedApp"
    language "C++"
    staticruntime "Off"

    targetdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includefirs
    {
        "src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:linux"
        systemversion "latest"

    filter "configurations:Debug"
        defines "TAIL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TAIL_RELEASE"
        runtime "Release"
        optimize "on"