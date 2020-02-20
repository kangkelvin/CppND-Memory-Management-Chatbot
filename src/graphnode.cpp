#include "graphnode.h"
#include "graphedge.h"

#include <iostream>

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &chatBot) {
  std::cout << std::endl;
  ChatBot chatBotStack("../images/chatbot.png");
  ChatBot* chatBotHeap = new ChatBot(std::move(chatBot));
  _chatBot = std::move(*chatBotHeap);
  delete chatBotHeap;
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(_chatBot);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}