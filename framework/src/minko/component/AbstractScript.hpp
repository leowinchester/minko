/*
Copyright (c) 2013 Aerys

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

#include "minko/component/AbstractComponent.hpp"
#include "minko/Signal.hpp"

namespace minko
{
	namespace component
	{
		class AbstractScript :
			public AbstractComponent,
			public std::enable_shared_from_this<AbstractScript>
		{
		public:
			typedef std::shared_ptr<AbstractScript> Ptr;

		private:
			typedef std::shared_ptr<scene::Node>		NodePtr;
			typedef std::shared_ptr<AbstractComponent>	AbsCmpPtr;

		private:
			std::unordered_map<NodePtr, bool>				_started;

			Signal<AbsCmpPtr, NodePtr>::Slot				_targetAddedSlot;
			Signal<AbsCmpPtr, NodePtr>::Slot				_targetRemovedSlot;
            Signal<NodePtr, NodePtr, NodePtr>::Slot         _addedSlot;
            Signal<NodePtr, NodePtr, NodePtr>::Slot         _removedSlot;
			Signal<NodePtr, NodePtr, AbsCmpPtr>::Slot		_componentAddedSlot;
			Signal<NodePtr, NodePtr, AbsCmpPtr>::Slot		_componentRemovedSlot;
			Signal<std::shared_ptr<SceneManager>>::Slot		_frameBeginSlot;

		protected:
			virtual
			void
			start(NodePtr target)
			{
				// nothing
			}

			virtual
			void
			update(NodePtr target)
			{
				// nothing
			}

			virtual
			void
			stop(NodePtr target)
			{
				// nothing
			}

		public:
			void
			initialize();

			void
			targetAddedHandler(AbsCmpPtr cmp, NodePtr node);

			void
			targetRemovedHandler(AbsCmpPtr cmp, NodePtr node);

            void
            addedOrRemovedHandler(NodePtr node, NodePtr target, NodePtr parent);

			void
			componentAddedHandler(NodePtr node, NodePtr	target, AbsCmpPtr component);

			void
			componentRemovedHandler(NodePtr	node, NodePtr target, AbsCmpPtr	component);

			void
			frameBeginHandler(std::shared_ptr<SceneManager> sceneManager);

			void
			setSceneManager(std::shared_ptr<SceneManager> sceneManager);
		};
	}
}
