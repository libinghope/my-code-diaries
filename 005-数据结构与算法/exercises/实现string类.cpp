
#define NULL 0
class String
{
public:
        String(const char *str = NULL);//普通构造函数
        String(const String &other); //拷贝构造函数
        //析构函数
        ~String(void);
        String &operate=(const String &other);
        inline char * getPtr(){return m_data;};
        inline int getLength(){return strlen(m_data);}
private:
        char *m_data;//用于保存字符串
};

String::String(const char *str = NULL){
    int len = strlen(str) + 1;  
    m_data = new char[len];  
    memset(m_data, 0, len);  
    strcpy(m_data, str)  
}

String::String(const String &other){
    int len = other.getLength() + 1;
    m_data = new char[len];
    memset(m_data, 0, len);
    strcpy(m_data, other.getPtr());
}

String::~String(void){
    if(m_data){
        delete[] m_data;
        m_data = NULL;
    }
}

String &operate=(const String &other){
    if(this == &other){
        return *this;
    }
    int len = other.getLength() + 1;  
    delete [] m_data;  
    m_data = new char[len];  
    memset(m_data, 0, len);  
    strcpy(m_data, other.getPtr());  
  
    return *this;  
}