FROM nimashoghi/slam_build_essentials:arm32v7

WORKDIR /root
COPY . .

# prepare build environment
RUN chmod +x ./build_pre.sh && ./build_pre.sh

# build
RUN chmod +x ./build.sh && ./build.sh


ENTRYPOINT ["/root/Examples/Monocular/mono_tum", "/root/Vocabulary/ORBvoc.txt", "/data/settings.yaml"]
