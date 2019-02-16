
# react-native-handshake-chat

## Getting started

`$ npm install react-native-handshake-chat --save`

### Mostly automatic installation

`$ react-native link react-native-handshake-chat`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-handshake-chat` and add `RNHandshakeChat.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNHandshakeChat.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.reactlibrary.RNHandshakeChatPackage;` to the imports at the top of the file
  - Add `new RNHandshakeChatPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-handshake-chat'
  	project(':react-native-handshake-chat').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-handshake-chat/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-handshake-chat')
  	```

#### Windows
[Read it! :D](https://github.com/ReactWindows/react-native)

1. In Visual Studio add the `RNHandshakeChat.sln` in `node_modules/react-native-handshake-chat/windows/RNHandshakeChat.sln` folder to their solution, reference from their app.
2. Open up your `MainPage.cs` app
  - Add `using Handshake.Chat.RNHandshakeChat;` to the usings at the top of the file
  - Add `new RNHandshakeChatPackage()` to the `List<IReactPackage>` returned by the `Packages` method


## Usage
```javascript
import RNHandshakeChat from 'react-native-handshake-chat';

// TODO: What to do with the module?
RNHandshakeChat;
```
  