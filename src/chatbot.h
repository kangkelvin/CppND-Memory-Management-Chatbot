#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <memory>
#include <string>

class GraphNode;  // forward declaration
class ChatLogic;  // forward declaration

class ChatBot {
 private:
  // data handles (owned)
  std::shared_ptr<wxBitmap> _image;  // avatar image

  // data handles (not owned)

  GraphNode *_rootNode;
  ChatLogic *_chatLogic;
  GraphNode *_currentNode;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

 public:
  // constructors / destructors
  ChatBot();                      // constructor WITHOUT memory allocation
  ChatBot(std::string filename);  // constructor WITH memory allocation
  ~ChatBot();

  //// STUDENT CODE
  ////

  ChatBot &operator=(const ChatBot &source);
  ChatBot(ChatBot &&source);
  ChatBot &operator=(ChatBot &&source);

  ////
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  wxBitmap *GetImageHandle() { return _image.get(); }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */