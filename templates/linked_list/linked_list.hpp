
namespace linked_list
{
template<class DataType>
class linked_list
{
public:

    linked_list(DataType value)
    {
        m_head = node(value);
        m_tail = m_head;
        m_size = 1;

    }

    linked_list() : m_head(NULL), m_tail(NULL), m_size(0)
    {

    }

    add(DataType value)
    {
        if (head == NULL)
        {
            m_head = node(value);
            m_tail = node(value);
        }
        else
        {
            temp = node(value);
            temp.set_previouse(tail);
            tail.set_next(temp);
            tail = temp;
        }

        ++m_size;
    }

    // Remove the first element with the value
    void remove(DataType value)
    {
        auto temp = head;

        while(temp != NULL)
        {
            if(temp.value() == value)
            {
                auto temp_previouse = temp.previouse();
                temp_previouse.set_next(temp.next());
                temp.next().set_previpuse(temp_previouse);
                --m_size;
                break;
            }
            else
            {
                temp = temp.next();
            }
        }
    }

    int size()
    {
        m_size;
    }

private:
    class node
    {
    public:
        node(DataType value) : m_value(value), m_next(NULL), m_previouse(NULL)
        {

        }

        node next()
        {
            return m_next;
        }

        void set_next(node next)
        {
            m_next = next;
        }

        node previouse()
        {
            return m_previouse;
        }

        void set_previouse(node previouse)
        {
            m_previouse = previouse;
        }

        DataType value()
        {
            return m_value;
        }

    private:
        DataType m_value;
        node m_next;
        node m_previouse;
    };

private:
    node m_head;
    node m_tail;
    int m_size;
}
}
