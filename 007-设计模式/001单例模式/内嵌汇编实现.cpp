/*假设一个公司只有一台打印机，给所有的员工使用，每次使用都有使用记录(简单的累计使用次数)*/
//内嵌汇编实现，并且保证线程安全
class Printer {
    protected:
    Printer() {
        }
    Printer(const Printer&){}
    public:

    /*下面这种写法在多线程情况下是不安全的
    当两个线程同时执行到if判断的时候(一个判断为否后挂起)，有可能会new多次，
    根本原因在于，c++的if判断，会被拆解为多个汇编指令(机器指令)，判断和赋值无法合并为原子操作
    */
    static Printer* getInstance(){
        if(!pPrinter){
            pPrinter = new Printer;
        }
        return pPrinter;
    }
    //用内嵌汇编实现原子操作
    static Printer* asm_getInstance(){
        if(!pPrinter){
            Printer* p = new Printer;
            if(!pPrinter->checkNewInstance(nullptr,p)){
                delete p;
            }else{
                pPrinter = p;
            }
        }
        return pPrinter;
    }

    private:
    static Printer * pPrinter;

    inline bool checkNewInstance(Printer * expectedP,Printer *newP){
        volatile void * pointer = this->pPrinter;
        /*下面的汇编代码中，lock cmpxchg 指令是原子操作，判断newP和pointer是否是同一个值(地址),
        该指令有两个操作数，第一个是目标操作数，第二个是源操作数
        该指令比较目标操作数ptr[EDX]和EAX中的值，如果二者相等(即pointer==expectedP==nullptr),
        也就是pointer为nullptr时,将源操作数写入目标操作数(newP赋值给EDX)，否则将
        目标操作数写入到EAX寄存器(将pointer赋值给EAX)。
        */
            __asm {
              mov EDX,pointer
              mov EAX,expectedP
              mov ECX,newP
              lock cmpxchg dword ptr[EDX],ECX
              mov newP,EAX
        }

        return expectedP == newP;
    }
};

Printer* Printer::pPrinter = nullptr;