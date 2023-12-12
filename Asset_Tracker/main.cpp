// Asset Tracker

/* The code allows the user to track assets. */

#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// Asset class representing individual assets
class Asset {
private:
  string name;
  string id;
  string location;

public:
  Asset(string assetName, string assetId, string assetLocation)
      : name(assetName), id(assetId), location(assetLocation) {}

  string getName() const { return name; }

  string getID() const { return id; }

  string getLocation() const { return location; }

  void setLocation(string newLocation) { location = newLocation; }
};

// AssetTracker class managing a collection of assets
class AssetTracker {
private:
  vector<Asset> assets;

public:
  void addAsset(const Asset &newAsset) { assets.push_back(newAsset); }

  Asset *getAssetByID(const string &assetID) {
    for (auto &asset : assets) {
      if (asset.getID() == assetID) {
        return &asset;
      }
    }
    return nullptr;
  }

  bool updateAssetLocation(const string &assetID, string newLocation) {
    Asset *asset = getAssetByID(assetID);
    if (asset != nullptr) {
      asset->setLocation(newLocation);
      return true;
    }
    return false;
  }

  void displayAllAssets() const {
    cout << "Assets in the tracker:" << endl;
    for (const auto &asset : assets) {
      cout << "Name: " << asset.getName() << ", ID: " << asset.getID()
           << ", Location: " << asset.getLocation() << endl;
    }
  }
};

int main() {
  AssetTracker tracker;

  Asset asset1("Laptop", "ADV80106", "EC1 - 2213M");
  Asset asset2("Laptop", "ADV201203", "EC1 - 2244C");
  Asset asset3("Laptop", "ADV220203", "EC1 - 2219H");

  tracker.addAsset(asset1);
  tracker.addAsset(asset2);
  tracker.addAsset(asset3);

  int choice;
  do {
    cout << "\nMenu:\n";
    cout << "1. Display all assets\n";
    cout << "2. Update asset location\n";
    cout << "3. Add new asset\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";

    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number: ";
    }

    switch (choice) {
    case 1:
      tracker.displayAllAssets();
      break;
    case 2: {
      string assetID, newLocation;

      cout << "Enter asset ID: ";
      cin >> assetID;

      cout << "Enter new location: ";
      cin.ignore();
      getline(cin, newLocation);

      if (tracker.updateAssetLocation(assetID, newLocation)) {
        cout << "Asset location updated successfully.\n";
      } else {
        cout << "Asset not found.\n";
      }
      break;
    }
    case 3: {
      string assetName, assetLocation, assetID;

      cout << "Enter asset name: ";
      cin.ignore();
      getline(cin, assetName);

      cout << "Enter asset ID: ";
      cin >> assetID;

      cout << "Enter asset location: ";
      cin.ignore();
      getline(cin, assetLocation);

      Asset newAsset(assetName, assetID, assetLocation);
      tracker.addAsset(newAsset);
      cout << "Asset added successfully.\n";
      break;
    }
    case 4:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Please enter a valid option.\n";
    }
  } while (choice != 4);

  return 0;
}
