# Auction
# Auction

# DB
account_room.txt - luu nguoi tham gia: user_id - room_id
account.txt - luu account: id - username - password - phone - address - status
auction.txt - luu room: id - user_id - name - create_at - status
item.txt - luu item: id - room_id - current_price - BIN_price - description - created_at - end - status - price_maker_id - reserve_price
# Features

# client
- sign in, sign up, logout
- create auction room
- join room
- out room
- create item
- kick account
- get items
- get room
- get participate
- Bid
- Bin
- delete item

=======
1: sign up
2: login - gui status neu OK, gui account hien tai
3: logout - gui status va out ra khoi cac phong hien tai
4: create auction room - gui status => mess update_room
5: join room - gui status => mess update_account_room
6: bid item - gui status => mess update_item
9: delete item - gui status => mess update_item
10: kick account - gui status => mess update_account_room
11: create item - gui status => update_item
14: get rooms - gui size room(char messs[BUFF_SIZE]) => gui tung room
16: bin item - gui status => mess update_item
18: get items - gui size room(char mess[BUFF_SIZE]) => gui tung room
19: out room - gui status => update_account_room
20: get participate - gui size participate(char mess[BUFF_SIZE]) => gui tung account (struct Account)
22: start auction => #OK
23: alert when remaning time equals 1 minute
