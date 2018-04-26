#define BOOST_TEST_MODULE OTUS_HW_5_TEST

#include <boost/test/unit_test.hpp>
#include "./library/document.h"
#include "./library/events.h"


BOOST_AUTO_TEST_SUITE(homework_5_test)

BOOST_AUTO_TEST_CASE(storage_test)
{
  Document testDocument{};
  testDocument.addShape(std::make_shared<Line>(Point{0,0}, Point{100,100}));
  testDocument.addShape(std::make_shared<Circle>(Point{50,50}, 50));

  testDocument.sendToDatabase();
  Document copy{testDocument};
  testDocument.receiveFromDatabase();
  //BOOST_CHECK(testDocument == copy);

  testDocument.saveToFile(std::string{"c:\\MyDocuments\\Doc1.vd"});
  copy = testDocument;
  testDocument.loadFromFile(std::string{"c:\\MyDocuments\\Doc1.vd"});
  //BOOST_CHECK(testDocument == copy);
}

BOOST_AUTO_TEST_CASE(template_test)
{

}

BOOST_AUTO_TEST_CASE(new_processing_test)
{

}

BOOST_AUTO_TEST_CASE(drawing_test)
{
  Document testDocument{};
  testDocument.addShape(std::make_shared<Line>(Point{0,0}, Point{100,100}));
  testDocument.addShape(std::make_shared<Circle>(Point{50,50}, 50));
  auto testView {new Window{std::string{"Test vindow"}, nullptr}};
  testDocument.setView(testView);
  testDocument.refreshView();

  Picture testPicture{/* load from file*/};
  //BOOST_CHECK(testPicture == testView->getPicture());
}


BOOST_AUTO_TEST_SUITE_END()
