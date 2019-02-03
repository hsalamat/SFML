#include "SceneNode.hpp"
int main()
{
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

	SceneNode	mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	std::unique_ptr<SceneNode> node11(new SceneNode());
	mSceneLayers[Background]->attachChild(std::move(node11));

	std::unique_ptr<SceneNode> node12(new SceneNode());
	mSceneLayers[Background]->attachChild(std::move(node12));

	std::unique_ptr<SceneNode> node21(new SceneNode());
	mSceneLayers[Air]->attachChild(std::move(node21));

	std::unique_ptr<SceneNode> node22(new SceneNode());
	mSceneLayers[Air]->attachChild(std::move(node22));


	mSceneGraph.detachChild(*mSceneLayers[Background]);
	mSceneGraph.detachChild(*mSceneLayers[Air]);

	system("pause");
}