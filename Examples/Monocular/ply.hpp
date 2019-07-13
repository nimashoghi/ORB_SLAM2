#pragma once

#include "System.h"
#include <fstream>
#include <vector>
#include <set>
#include <opencv2/core.hpp>

inline auto write_ply(ORB_SLAM2::System &system) -> void
{
    const auto keyframes = system.mpMap->GetAllKeyFrames();

    std::set<ORB_SLAM2::MapPoint *> points;
    for (const auto keyframe : keyframes)
    {
        for (const auto point : keyframe->GetMapPoints())
        {
            points.insert(point);
        }
    }

    std::ofstream file("./pc.ply");
    file << std::string{"ply\n"};
    file << std::string{"format binary_little_endian 1.0\n"};
    file << std::string{"element vertex "} << points.size() << std::string{"\n"};
    file << std::string{"property float x\n"};
    file << std::string{"property float y\n"};
    file << std::string{"property float z\n"};
    file << std::string{"property float intensity\n"};
    file << std::string{"end_header\n"};
    for (const auto point : points)
    {
        const auto pos = point->GetWorldPos();
        float pos_array[3] = {
            pos.at<float>(0),
            pos.at<float>(1),
            pos.at<float>(2),
        };

        file.write((const char *)pos_array, 3 * sizeof(float));
        float color = 255.0 / 255.0;
        file.write((const char *)&color, sizeof(float));
    }
    file.close();
}
