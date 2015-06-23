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
