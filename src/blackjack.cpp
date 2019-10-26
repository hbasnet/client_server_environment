#include <iostream>
#include "blackjack.h"

bool hand::is21()
{
   int total = 0;
   for (auto it = cards.begin(); it != cards.end(); ++it) 
   {
      total = total + it->value;
   }
   return total==21;
}

void hand::addCard(card C)
{
   cards.push_back (C);
}

hand::hand ()
{
}

hand::~hand ()
{
}
