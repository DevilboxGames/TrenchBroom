/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRENCHBROOM_TAGMANAGER_H
#define TRENCHBROOM_TAGMANAGER_H

#include "StringUtils.h"

#include <set>

namespace TrenchBroom {
    namespace Model {
        class Tag;
        class SmartTag;
        class Taggable;

        /**
         * Manages the tags used in a document and updates smart tags on taggable objects.
         */
        class TagManager {
        private:
            std::set<SmartTag> m_smartTags;
        public:
            /**
             * Returns a set containing all smart tags registered with this manager.
             */
            const std::set<SmartTag>& smartTags() const;

            /**
             * Returns the smart tag with the given name.
             *
             * @param name the name of the smart tag with the given name
             * @return the smart tag with the given name
             *
             * @throws std::logic_error if no tag with the given name is registered
             */
            const SmartTag& smartTag(const String& name) const;

            /**
             * Register the given smart tag with this tag manager.
             *
             * @param tag the smart tag to register
             *
             * @throws std::logic_error if the given smart tag is already registered
             */
            void registerSmartTag(SmartTag tag);

            /**
             * Clears all registered smart tags;
             */
            void clearSmartTags();

            /**
             * Update the smart tags of the given taggable object.
             *
             * @param taggable the object to update
             */
            void updateTags(Taggable& taggable) const;
        };
    }
}

#endif //TRENCHBROOM_TAGMANAGER_H
