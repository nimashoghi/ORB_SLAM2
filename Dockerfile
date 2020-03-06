FROM nimashoghi/ubuntu-xenial-orb-slam2-runtime-deps:2-13-20

WORKDIR /build/ORB_SLAM2
COPY . .
RUN mkdir install \
    && mkdir build \
    && cd build \
    && cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make -j \
    && make install

RUN rm -rf /build/

WORKDIR /root
ADD ./Vocabulary/ORBvoc.txt.tar.gz .
