#include "SortedLinkedList.h"

/***** Complete this class. *****/


SortedLinkedList::SortedLinkedList():head(nullptr) 
{
   
}

SortedLinkedList::~SortedLinkedList()
{
   
}
void SortedLinkedList::insert(Node *node)
{
    if (nullptr == head)//Inserting first node
    {
        head = node;
        node->next = nullptr;
        node->previous = nullptr;
    }
    else if (*head > *node)//Inserting at beggining
    {
            node->next = head;
            node->previous = nullptr;
            head->previous = node;
            head = node;
    }
    else
    {
            Node* current = head;
            while (true)
            {
                if (!(current->next))//Inserting at the end
                {
                	  current->next = node;
                    node->previous = current;
                    node->next = nullptr;
                    break;
                }

               else if (*(current->next) > *(node))//inserting in the middle
                {
                    Node *temp = nullptr;
                    temp = current->next;
                    current->next = node;
                    node->previous = current;
                    node->next = temp;
                    temp->previous = node;

                    break;
                }
                else
                {
                	current = current->next;
                }
            }//end of while
       }

}


ostream& operator <<(ostream& out, const SortedLinkedList& list)
{

	Node *temp = list.head;
	unsigned int row_curr = 0;
	unsigned int col_curr = 0;
	unsigned int row_prev = 0;
	unsigned int col_prev = 0;
	unsigned int end_prev = 0;
   

	 int newline = 0;
	 int space = 0;
	 int diff_space = 0;
	 int newline_count = 0;
	 int space_count = 0;
	

	 while(temp != nullptr)
	 {
      if(temp == list.head)
		{
         newline = temp->get_row();
			space = temp->get_col() -1;
      }
		else
		{
			 row_curr = temp->get_row();
			 col_curr = temp->get_col();
			 row_prev = temp->previous->get_row();
			 col_prev = temp->previous->get_col();
			 
			 if(row_curr == row_prev)
			 {
			    if(col_curr == col_prev ||col_curr < end_prev)
			    {
			       temp = temp->next;
                continue;
			    }
			 }
			 
			   newline = row_curr-row_prev;
			   if(newline > 0)
			   {
				   space = col_curr;
			   }
			   else
			   {
	           space = col_curr-end_prev;
			   }
			 
      }
 
      //handling length of city and state name 
      if(temp->get_name().length()>0)
		{
		    end_prev = temp->get_col() + temp->get_name().length() + temp->get_state().length() + 2;
		}
		else
		{
		     end_prev = temp->get_col() + 1;
		}
               
      //iterating over new lines
		for(int i = newline_count; newline_count < newline;newline_count++ )
		{
			 out << endl;
		}
		
		//iterating over spaces	 	 
		for(int i = space_count; space_count < space;space_count++ )
		{
			 out << " ";
		}
		
		out << *temp;
		temp = temp->next;
      newline_count = 0;
		space_count = 0;
	 }
   return out;
}





