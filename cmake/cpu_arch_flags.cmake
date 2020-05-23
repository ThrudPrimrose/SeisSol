function(get_arch_flags architecture compiler)
    # Westmere cpu architecture
    if ("${HOST_ARCH}" STREQUAL "wsm")
        set(CPU_ARCH_FLAGS "-msse3" PARENT_SCOPE)
    
    # Sandy Bridge cpu architecture
    elseif ("${HOST_ARCH}" STREQUAL "snb")
        set(CPU_ARCH_FLAGS "-mavx" PARENT_SCOPE)
    
    # Haswell cpu architecture
    elseif ("${HOST_ARCH}" STREQUAL "hsw")
        if (compiler STREQUAL "Intel")
            set(CPU_ARCH_FLAGS "-xCORE-AVX2" "-fma" PARENT_SCOPE)
        elseif(compiler STREQUAL "GNU")
            set(CPU_ARCH_FLAGS "-O2" "-mavx2" "-mfma" PARENT_SCOPE)
            #set(CPU_ARCH_FLAGS "-O2" "-mavx2" "-mfma" PARENT_SCOPE)
        endif()

    # Knights Corner (Xeon Phi)
    elseif ("${HOST_ARCH}" STREQUAL "knc")
        set(CPU_ARCH_FLAGS "-mmic" "-fma" PARENT_SCOPE)
    
    # Knight Landing (Xeon Phi)
    elseif ("${HOST_ARCH}" STREQUAL "knl")
        if (compiler STREQUAL "Intel")
            set(CPU_ARCH_FLAGS "-xMIC-AVX512" "-fma" PARENT_SCOPE)
        elseif(compiler STREQUAL "GNU")
            set(CPU_ARCH_FLAGS "-mavx512f" "-mavx512cd" "-mavx512pf" "-mavx512er" "-mfma" PARENT_SCOPE)
        endif()
    
    # Skylake cpu architecture
    elseif ("${HOST_ARCH}" STREQUAL "skx")
        if (compiler STREQUAL "Intel")
            set(CPU_ARCH_FLAGS "-xMIC-AVX512" "-fma" PARENT_SCOPE)
        elseif(compiler STREQUAL "GNU")
            set(CPU_ARCH_FLAGS "-march=skylake-avx512" PARENT_SCOPE)
        endif()

    # IBM power
    elseif ("${HOST_ARCH}" STREQUAL "power9")
        set(CPU_ARCH_FLAGS "-mtune=power9" PARENT_SCOPE)

    endif()

endfunction()
