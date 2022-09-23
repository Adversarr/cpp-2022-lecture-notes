cmake_minimum_required(VERSION 3.18)

project(cpp2022_all)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)



function(add_task week task)
  set(task_dir ${CMAKE_CURRENT_SOURCE_DIR}/${week}/${task})

  if(EXISTS ${task_dir})
    if(EXISTS "${task_dir}/CMakeLists.txt")
      add_subdirectory(${task_dir})
    else()
      if(NOT EXISTS ${task_dir}/source)
        message(FATAL_ERROR "${week} ${task} source not found")
      endif()

      file(GLOB sources ${task_dir}/source/*)
      add_executable(${week}_${task} ${sources})
      message(STATUS "=> Executable: ${week}_${task}; Source file(s): ${sources}")

      if(EXISTS ${task_dir}/include)
        target_include_directories(${week}_${task} PUBLIC ${task_dir}/include)
      else()
        message(STATUS ":: No headers.")
      endif()

      if (EXISTS ${task_dir}/asset)
        target_compile_definitions(${week}_${task} PUBLIC ASSET_DIR="${task_dir}/asset")
        message(STATUS ":: Target asset is set.")
      endif()

      set_target_properties(${week}_${task} PROPERTIES
        CXX_STANDARD 17
        LINKER_LANGUAGE CXX)
    endif()
  endif()
endfunction()

function(build_week w)
  if(IS_DIRECTORY ${w})
    message(STATUS ":: Entering ${w}")
    file(GLOB tasks LIST_DIRECTORIES true ${w}/*)

    foreach(t IN LISTS tasks)
      if(IS_DIRECTORY ${t})
        file(RELATIVE_PATH week ${CMAKE_CURRENT_SOURCE_DIR} ${w})
        file(RELATIVE_PATH task ${w} ${t})
        add_task(${week} ${task})
      endif()
    endforeach(t)
  endif()
endfunction()

function(build_all)
  file(GLOB groups LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/*)

  foreach(w IN LISTS groups)
    build_week(${w})
  endforeach()
endfunction()

if(DEFINED WEEK)
  message(STATUS "Week: ${WEEK}")
  build_week("${CMAKE_CURRENT_SOURCE_DIR}/${WEEK}")
else()
  message(STATUS "configure all.")
  build_all()
endif()
