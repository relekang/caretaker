# Services on macOS
## launchd

#### 1. Create  ~/Library/LaunchAgents/com.rolflekang.caretaker.plist

Ensure that the path in `ProgramArguments` is correct by running `which caretaker`.

```xml
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
  <dict>
    <key>KeepAlive</key>
    <dict>
      <key>SuccessfulExit</key>
      <false/>
    </dict>
    <key>Label</key>
    <string>com.rolflekang.caretaker</string>
    <key>ProgramArguments</key>
    <array>
      <string>/usr/local/bin/caretaker</string>
      <string>--standing-desk</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
    <key>WorkingDirectory</key>
    <string>/usr/local/var</string>
    <key>StandardErrorPath</key>
    <string>/usr/local/var/log/caretaker.log</string>
    <key>StandardOutPath</key>
    <string>/usr/local/var/log/caretaker.log</string>

    <key>EnvironmentVariables</key>
    <dict>
      <key>PATH</key>
      <string>/bin:/usr/bin:/usr/local/bin</string>
    </dict>
  </dict>
</plist>
```

#### 2. Load the service into launchd

```shell
launchctl load ~/Library/LaunchAgents/com.rolflekang.caretaker.plist
```

#### 3. Load the service into launchd

```shell
launchctl start com.rolflekang.caretaker
```

#### 4. Check the log to ensure it started correctly

```shell
tail /usr/local/var/log/caretaker.log
```
