namespace Crazycraft{

    struct Texture
    {
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

    };
    

    struct Block{

        std::string name;
        char maxstack;

        Texture textures;

        Block(std::string newname,char newmaxstack,Texture t){
            textures = t;
            name = newname;
            maxstack = newmaxstack;
        }

    };

    class Blocks{
        private:
        static std::vector<Block> blocksi;
        Blocks(){}
        public:
        void addBlock(Block b){
                blocksi.push_back(b);
        }
        Block getBlock(int b){
            return blocksi[b];
        }
        Blocks getInstance(){
          return Blocks();
        }

       
    };

}