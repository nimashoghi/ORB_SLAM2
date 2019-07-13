# FROM nimashoghi/slam_build_essentials:xenial-arm64
FROM nimashoghi/slam_build_essentials:arm32v7

WORKDIR /root
COPY . .

# prepare build environment
RUN chmod +x ./build_pre.sh && ./build_pre.sh

# build
RUN chmod +x ./build.sh && ./build.sh

WORKDIR /root/bin
