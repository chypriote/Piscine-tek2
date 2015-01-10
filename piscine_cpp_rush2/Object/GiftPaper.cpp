//
// Giftpaper.cpp for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 14:26:18 2014 Pierre Enjalbert
// Last update Sun Jan 19 01:24:52 2014 Nicolas Temenides
//

#include	<string>
#include	<iostream>
#include	"GiftPaper.hh"

GiftPaper::GiftPaper() {
  is_open = true;
  object = NULL;
  _type = GIFTPAPER;
}

GiftPaper::~GiftPaper() { }

std::string GiftPaper::getTitle() {
  return "a beautiful gift paper"; }
