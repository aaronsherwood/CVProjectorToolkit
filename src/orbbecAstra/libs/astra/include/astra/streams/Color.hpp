// This file is part of the Orbbec Astra SDK [https://orbbec3d.com]
// Copyright (c) 2015 Orbbec 3D
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Be excellent to each other.
#ifndef ASTRA_COLOR_HPP
#define ASTRA_COLOR_HPP

#include "../../astra_core/astra_core.hpp"
#include "../capi/astra_ctypes.h"
#include "../capi/streams/color_capi.h"
#include "Image.hpp"

namespace astra {

    class ColorStream : public ImageStream
    {
    public:
        explicit ColorStream(astra_streamconnection_t connection)
            : ImageStream(connection)
        {
            colorStream_ = reinterpret_cast<astra_colorstream_t>(connection);
        }

        static const astra_stream_type_t id = ASTRA_STREAM_COLOR;


    private:
        astra_colorstream_t colorStream_;
    };

    class ColorFrame : public ImageFrame<RgbPixel, ASTRA_STREAM_COLOR>
    {
    public:
        ColorFrame(astra_imageframe_t frame)
            : ImageFrame(frame, ASTRA_PIXEL_FORMAT_RGB888)
        {}
    };

    class RawColorFrame : public ImageFrame<uint8_t, ASTRA_STREAM_COLOR>
    {
    public:
        RawColorFrame(astra_imageframe_t frame)
            : ImageFrame(frame, ASTRA_PIXEL_FORMAT_RGB888)
        {}
    };
}

#endif // ASTRA_COLOR_HPP
