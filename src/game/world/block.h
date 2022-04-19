namespace Crazycraft{


    struct Texture
    {
        public:
        unsigned char front;
        unsigned char back;
        unsigned char left;
        unsigned char right;
        unsigned char up;
        unsigned char down;

        Texture(){
        front =0;
        back = 0;
        left = 0;
        right = 0;
        up = 0;
        down = 0;
        }

        Texture(unsigned char _front,unsigned char _back,unsigned char _left,unsigned char _right,unsigned char _up,unsigned char _down){
        front = _front;
        back = _back;
        left = _left;
        right = _right;
        up = _up;
        down = _down;
        }
        int Gett(int FaceId){
            switch (FaceId)
            {
            case 0:
                return front;
            case 1:
                return back;
            case 2:
                return left;
            case 3:
                return right;
            case 4:
                return up;
            case 5:
                return down;

            default:
                break;
            }
        }

    };
    

    struct Block{
        public:
        std::string name;
        char maxstack;

        Texture textures;

        Block(std::string newname,char newmaxstack,Texture t = Texture()){
            textures = t;
            name = newname;
            maxstack = newmaxstack;
        }

    };

    class BlockDefs{
        private:
        static std::vector<Block> bdata;
        public:
        void addBlock(Block b){
            bdata.push_back(b);
        }
        Block getBlockData(int b){
            return bdata[b];
        }
        BlockDefs(){
          
        }
    };

      

}