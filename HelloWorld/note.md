**去除Warning**

Arduino输出控制台会出现如下警告

`[Warning] Output path is not specified. Unable to reuse previously compiled files. Upload could be slow. See README.`

解决方法：

在`.vscode -> arduino.json`中添加`"output": "./build"`

---

**去除乱码**

Arduino输出控制台输出中文时会出现乱码

解决方法：

打开Arduino扩展插件的目录，即`vsciot-vscode.vscode-arduino`中的`out\src\common\util.js`文件，将如下代码注释掉

```js
if (os.platform() === "win32") {
    try {
        const chcp = child_process.execSync("chcp.com");
        codepage = chcp.toString().split(":").pop().trim();
    }
    catch (error) {
        outputChannel_1.arduinoChannel.warning(`Defaulting to code page 850 because chcp.com failed.\
        \rEnsure your path includes %SystemRoot%\\system32\r${error.message}`);
        codepage = "850";
    }
}
```

---

**线路连接**

| OLED | NodeMCU |
| ---- | ------- |
| GND  | GND     |
| VCC  | 3V / 5V |
| SCL  | D1      |
| SDA  | D2      |

