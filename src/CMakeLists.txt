file (GLOB SRCS *.cpp *.h)
file (GLOB CUDA_SRCS *.cu *.cuh)

add_library (Supernova ${SRCS} ${CUDA_SRCS})
