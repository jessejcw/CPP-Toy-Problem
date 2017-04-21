//
// Created by jesse wang on 2/28/17.
//

#ifndef CODE1_RB_H
#define CODE1_RB_H

template <typename ET, int SZ, typename ST=int>
class RB {
    typedef ET value_type;
    typedef ST size_type;
protected:
    value_type      m_buff[SZ];
    size_type       m_size = 0;
    size_type       m_front = 0;
    size_type       m_back = SZ-1;
    void clear() {
        m_size =0;
        m_front=0;
        m_back =SZ-1;
    }
public:
    RB() {
        clear();
    }
    ~RB() {}
    size_type size()    const {return m_size;}
    value_type& back()        {return m_buff[m_back];}
    value_type& front()       {return m_back[m_front];}

    void push() {
        m_back = (m_back+1) % SZ;
        if (size() == SZ) {
            m_front = (m_front+1) % SZ;
        } else {
            m_size++;
        }
    }
    void push(const value_type& x) {
    }
    void pop() {
    }
};


#endif //CODE1_RB_H
