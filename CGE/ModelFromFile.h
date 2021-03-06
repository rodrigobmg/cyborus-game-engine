#ifndef MODELFROMFILE_H
#define MODELFROMFILE_H

#include "Displayable.h"
#include "OpenGL/Texture2D.h"
#include "OpenGL/InterleavedVBO.h"
#include "c3m.h"

#include <string>
#include <iostream>

namespace CGE
{
    class ModelFromFile : public Displayable
    {
        public:
            ModelFromFile(const char* inFile);
            virtual ~ModelFromFile();

            virtual void display();

            enum BufferObject
            {
                VERTEX_BUFFER = 0,
                NORMAL_BUFFER = 1,
                COLOR_BUFFER = 2,
                TEXTURE_BUFFER = 3
            };

        protected:
            ModelFromFile()
            {
                mVBO.addField(0, 3);
                mVBO.addField(1, 2);
            }
            void loadC3M(const char* inFile);

            Texture2D mTexture;
            InterleavedVBO mVBO;
            IndexVBO mIVBO;
    };
}

#endif
