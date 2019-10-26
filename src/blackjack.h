#include <deque>

typedef enum {DIAMONDS,HEARTS,CLUBS,SPADES} SUITE;
class card
{
 public:
   int value;
   SUITE suite;
};

class hand
{
 public:
   std::deque<card> cards;
   bool is21();
   void addCard(card);
   hand ();
   ~hand ();
};
