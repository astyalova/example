# Start via `make test-debug` or `make test-release`
async def test_basic(service_client):
    response = await service_client.post('/add', params={'add': 'Tester'})
    assert response.status == 200
    assert response.text == 'Hello, Tester!\n'
