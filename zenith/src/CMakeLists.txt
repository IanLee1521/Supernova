file (GLOB SRCS *.cpp)
file (GLOB HDRS *.h)
#file (GLOB CUDA_SRCS *.cu *.cuh)

source_group (Sources FILES ${SRCS})
source_group (Headers FILES ${HDRS})

add_executable (zenith ${SRCS} ${HDRS})
