#ifndef Picture_H
#define Picture_H
#include <map>
#include <string>
#include "../../figureset.h"
#include "poimage.h"
namespace PO
{
    struct Picture:public VertexInfo,public ColorInfo,public TexCoorInfo
    {
        ImageManager::ImageIndex IS;
        operator const GraphicTexture& () const {return *IS->GetGraphic();}
        //operator ImageManager::ImageIndex& (){return IS;}
        void DrawPicture(Render& L)
        {
            Draw_Color DC(L,*this,*this);
            Draw_TexCoor DT(L,*this,*this);
            Draw_Texture DT2(L,*IS);
            Draw_Vertex DV(L,*this);
        }
        void Create(ImageManager& IM,const std::string& S) throw( PictureUnavailable )
        {
            IS=IM.CreateImage(S);
        }
        void Free(){  decltype(IS) Empty;IS=Empty;}
    };

    /*namespace Pattern{
        namespace Pic{
            void SetEqualRectangle(
                                   Picture&,
                                   float,
                                   const Vertex<2>& Shift=Ver(0.0,0.0),
                                   const Color<4>& C=Col(1.0,1.0,1.0,1.0)
                                   );
            inline void Translate(Picture& ST,const Normal<2>& L){ Pattern::Tex::Translate(ST.PD,L);}
            inline void Reset(Picture& ST,const Vertex<2>& P){  Pattern::Tex::Reset(ST.PD,P);}
            inline void Reset(Picture& ST,const Color<4>& P){  Pattern::Tex::Reset(ST.PD,P);}
        }
    }*/

}
#endif // Picture_H
