#pragma once

namespace CK
{
namespace DD
{

struct OrderByHash
{
	inline bool operator () (const std::unique_ptr<GameObject>& _left, const std::string& _right) const
	{
		return _left->GetHash() < std::hash<std::string>()(_right);
	}
};

class GameEngine
{
public:
	GameEngine() = default;

public:
	bool Init(const ScreenPoint& InViewportSize);
	bool LoadResources();
	bool LoadScene();

	// �Է� ������
	InputManager& GetInputManager() { return _InputManager; }

	// ���� ������Ʈ
	std::vector<std::unique_ptr<DD::GameObject>>& GetGameObject() { return _GameObjects; }
	std::vector<std::unique_ptr<DD::GameObject>>::const_iterator GoBegin() const { return _GameObjects.begin(); }
	std::vector<std::unique_ptr<DD::GameObject>>::const_iterator GoEnd() const { return _GameObjects.end(); }
	bool InsertGameObject(std::unique_ptr<GameObject> InGameObject);
	DD::GameObject& FindGameObject(std::string InName);

	// �޽�
	const DD::Mesh& GetMesh(const std::string& InMeshKey) { return *_Meshes[InMeshKey].get(); }

	// ī�޶� 
	DD::Camera& GetCamera() { return *_Camera.get(); }

	const static std::string QuadMeshKey;
	const static std::string PlayerKey;

private:
	ScreenPoint _ViewportSize;
	InputManager _InputManager;
	std::vector<std::unique_ptr<DD::GameObject>> _GameObjects;
	std::unordered_map<std::string, std::unique_ptr<DD::Mesh>> _Meshes;
	std::unique_ptr<DD::Camera> _Camera;
};

}
}