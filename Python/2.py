import requests
import json
ua={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36"
}
# date={"action":"next","messages":[{"id":"aaa27089-8805-4c19-8166-13bdbec38011","author":{"role":"user"},"content":{"content_type":"text","parts":["你知道burpsuite抓包软件吗"]},"metadata":{}}],"conversation_id":"d9bc1f82-c20c-4b47-b6ee-c7ba50717819","parent_message_id":"fd845648-07db-40de-83bc-fcf162017be0","model":"text-davinci-002-render-sha","timezone_offset_min":-480,"suggestions":[],"history_and_training_disabled":false,"conversation_mode":{"kind":"primary_assistant"},"force_paragen":false,"force_paragen_model_slug":"","force_nulligen":false,"force_rate_limit":false,"websocket_request_id":"cb554614-bb8d-4145-8ac0-2705352f6e40"}
# json_date=json.dumps(date)
date={
    "parts":["你知道burpsuite抓包软件吗"]
}
proxies={
    'http':'http://127.0.0.1:7890',
    'https':'http://127.0.0.1:7890',
}
url='https://www.youtube.com/'
re=requests.post(url,headers=ua,proxies=proxies,data=date)
print(re.status_code)