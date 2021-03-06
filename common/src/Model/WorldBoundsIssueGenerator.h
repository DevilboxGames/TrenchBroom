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

#ifndef TrenchBroom_WorldBoundsIssueGenerator
#define TrenchBroom_WorldBoundsIssueGenerator

#include "TrenchBroom.h"
#include "Model/IssueGenerator.h"
#include "Model/ModelTypes.h"

#include <vecmath/bbox.h>

namespace TrenchBroom {
    namespace Model {
        class WorldBoundsIssueGenerator : public IssueGenerator {
        private:
            class WorldBoundsIssue;
            class WorldBoundsIssueQuickFix;
        private:
            const vm::bbox3 m_bounds;
        public:
            WorldBoundsIssueGenerator(const vm::bbox3& bounds);
        private:
            void doGenerate(Entity* brush, IssueList& issues) const override;
            void doGenerate(Brush* brush, IssueList& issues) const override;
        };
    }
}

#endif /* defined(TrenchBroom_WorldBoundsIssueGenerator) */
