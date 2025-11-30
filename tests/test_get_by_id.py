
async def test_add_task_and_get(service_client):
    tasks_data: List[Dict[str, str]] = [
        {"title": "My task", "description": "Test description", "status": "todo"},
        {"title": "My task2", "description": "Test description", "status": "todo"},
        {"title": "My task3", "description": "Test description", "status": "todo"},
    ]

    created_tasks: List[Dict[str, str]] = []

    for task in tasks_data:
        response = await service_client.post('/add', json=task)
        assert response.status == 200
        created_task = response.json()
        created_tasks.append(created_task)

    response = await service_client.get('/get')
    assert response.status == 200
    all_tasks = response.json()
    all_task_ids = [task['id'] for task in all_tasks]

    for task in created_tasks:
        assert task['id'] in all_task_ids

    for task in created_tasks:
        task_id = task['id']
        response = await service_client.get(f'/get/{task_id}')
        assert response.status == 200
        single_task = response.json()
        assert single_task['id'] == task_id
        assert single_task['title'] == task['title']
        assert single_task['description'] == task['description']
        assert single_task['status'] == task['status']
