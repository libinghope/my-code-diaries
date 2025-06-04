class Component {
    public: virtual void show() = 0;
};

class Avatar: public Component {
    public: virtual void show();
};

//服饰类
class FineryDecoration: public Component {
    public: FineryDecoration(Component * component);
    virtual void show() = 0;
    protected: Component * component;
};

//T恤
class TShirts: public FineryDecoration {
    public: TShirts(Component * component);
    virtual void show();
};

//喇叭裤
class BellBottoms: public FineryDecoration {
    public: BellBottoms(Component * component);
    virtual void show();
};

//破球鞋
class PoSneakers: public FineryDecoration {
    public: PoSneakers(Component * component);
    virtual void show();
};
