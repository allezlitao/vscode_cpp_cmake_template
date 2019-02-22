set(TestFiles 
    T
)

set(UsedLib
  glog
  gtest
  pthread
)

foreach(TestFile ${TestFiles})

add_executable(${TestFile} "${TestFile}.cpp")
target_link_libraries(${TestFile} ${UsedLib})

endforeach()
