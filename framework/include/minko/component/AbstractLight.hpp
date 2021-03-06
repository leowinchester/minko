/*
Copyright (c) 2014 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "minko/Common.hpp"

#include "minko/Signal.hpp"
#include "minko/component/AbstractRootDataComponent.hpp"
#include "minko/data/ArrayProvider.hpp"
#include "minko/scene/Layout.hpp"

namespace minko
{
    namespace data
    {
        class LightMaskFilter;
    }

    namespace component
    {
        class AbstractLight :
            public AbstractRootDataComponent<data::ArrayProvider>
        {
            friend class data::LightMaskFilter;

        public:
            typedef std::shared_ptr<AbstractLight>         Ptr;

        private:
            typedef    std::shared_ptr<scene::Node>        NodePtr;
            typedef std::shared_ptr<AbstractComponent>     AbsCmpPtr;

        private:
            std::shared_ptr<math::Vector3>                 _color;

            Signal<NodePtr, NodePtr>::Slot                 _targetLayoutChangedSlot;

        public:
            inline
            std::shared_ptr<math::Vector3>
            color()
            {
                return _color;
            }

            Ptr
            color(std::shared_ptr<math::Vector3>);

            Ptr
            color(std::shared_ptr<math::Vector4>);

            Ptr
            color(uint color);

            Layouts
            layoutMask() const
            {
                return AbstractComponent::layoutMask();
            }

            void
            layoutMask(Layouts value);

        protected:
            AbstractLight(const std::string& arrayName);

            void
            targetAddedHandler(AbsCmpPtr, NodePtr);

            void
            targetRemovedHandler(AbsCmpPtr, NodePtr);

            void
            targetLayoutsChangedHandler(NodePtr, NodePtr);
        };
    }
}
